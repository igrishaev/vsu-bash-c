#!/bin/bash

PS3='Please enter your choice: '
options=("Option 1" "Input manualy" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Option 1")
            echo "you chose choice 1"
            ;;
        "Input manualy")
            echo "Enter command #1:"
            read CMD1
            echo "Enter command #2:"
            read CMD2

            echo "CMD1 = $CMD1" > Definitions
            echo "CMD2 = $CMD2" >> Definitions

            echo "Commands saved."
            break
            ;;
        "Quit")
            break
            ;;
        *) echo invalid option;;
    esac
done
