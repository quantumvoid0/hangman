#!/usr/bin/env bash
set -e

ACTION=$1
USER=$USER
HANGMAN=/home/$USER/.local/bin/
STICK=/home/$USER/.local/bin/

if [[ -z "$ACTION" ]]; then
    echo "Usage: $0 [install|uninstall]"
    exit 1
fi

if [[ "$ACTION" == "install" ]]; then
    echo "Compiling binaries..."
    gcc main.c -o hangman

    echo "Installing binaries to $HANGMAN..."
    install -Dm755 hangman "$HANGMAN/hangman"

    echo "Creating art dir at $STICK..."
    mkdir -p $STICK
    cp -r stick $STICK

    echo "Installation complete!"

elif [[ "$ACTION" == "uninstall" ]]; then
    echo "Removing binaries..."
    rm -f "$HANGMAN/hangman"
    echo "Removing art..."
    rm -rf "$STICK/stick"

    echo "Uninstallation complete!"

else
    echo "Unknown action: $ACTION"
    echo "Usage: $0 [install|uninstall]"
    exit 1
fi

