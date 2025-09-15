#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    const char *words[] = {
    "apple", "banana", "cherry", "dragon", "eagle",
    "falcon", "guitar", "house", "island", "jungle",
    "kiwi", "lemon", "mountain", "night", "ocean",
    "piano", "river", "sun", "tiger", "umbrella",
    "violin", "wolf", "karting", "yacht", "zebra",
    "ant", "ball", "cat", "dog", "egg", "frog",
    "goat", "hat", "ice", "jam", "kite", "lion",
    "mouse", "nest", "owl", "pig", "quail", "rat",
    "snake", "tree", "vase", "whale", "xenon",
    "apricot", "blueberry", "coconut", "dolphin",
    "elephant", "flamingo", "grape", "hippo", "iguana",
    "jackal", "kangaroo", "lemur", "mango", "narwhal",
    "octopus", "penguin", "quokka", "raccoon", "seahorse",
    "toucan", "vulture", "walrus", "xerus", "zebra",
    "avocado", "bread", "carrot", "donut", "enchilada",
    "jupiter", "ginger", "honey", "iceberg", "antartica",
    "hangman", "lasagna", "muffin", "noodle", "omelet",
    "pancake", "stickman", "rice", "sushi", "taco",
    "tiktok", "cliche", "waffle", "xigua", "yogurt",
    "resonance", "actor", "baker", "captain", "driver",
    "engineer", "farmer", "gardener", "hunter", "inventor",
    "juggler", "king", "leader", "merchant", "navigator",
    "officer", "pilot", "runner", "sailor", "teacher",
    "umpire", "villager", "writer", "yodeler", "zookeeper",
    "balloon", "candle", "desk", "fork", "glove", "hammer",
    "igloo", "jacket", "key", "lamp", "mirror", "notebook",
    "orange", "pencil", "quiver", "rope", "scarf", "table",
    "umbrella", "vase", "watch", "xylophone", "yarn", "zipper",
    "basket", "cloud", "door", "ear", "feather", "garden",
    "hill", "insect", "jar", "kite", "leaf", "mountain",
    "nest", "oar", "path", "linux", "river", "stone",
    "train", "uniform", "valley", "window", "xylophone", "yard", "zoo"
    };


    int size = sizeof(words) / sizeof(words[0]);
    srand(time(NULL));
    int random_index = rand() % size;
    int wlen = strlen(words[random_index]);
    char lines[256];
    for (int i = 0; i < wlen; i++) lines[i] = '_';
    lines[wlen] = '\0';
    printf("welcome to hangman\n");
    printf("your word is '%d' letters long\n\n", wlen);
    printf("%s\n", lines);

    int j = 1;
    char guess[4];

    while (1) {
        printf("Your guess (single letter): ");
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = 0;
        if (strlen(guess) != 1) {
            printf("Enter exactly one letter!\n");
            continue;
        }
        char c = guess[0];

        char *pos = strchr(words[random_index], c);
        if (pos != NULL) {
            while (pos != NULL) {
                int idx = pos - words[random_index];
                if (idx >= 0 && idx < wlen)
                    lines[idx] = c;
                pos = strchr(pos + 1, c);
            }
            printf("%s\n", lines);
            if (strcmp(lines, words[random_index]) == 0) {
                printf("you guessed it: %s\n", words[random_index]);
                break;
            }
        } else {
            printf("letter '%c' from your guess is wrong\n", c);
            char cmd[256];
            sprintf(cmd, "cat stick/%d", j);
            system(cmd);
            j++;
            if (j > 7) {
                system("cat stick/7");
                printf("you lost! the word was: %s\n", words[random_index]);
                return 1;
            }
        }
    }

    return 0;
}

