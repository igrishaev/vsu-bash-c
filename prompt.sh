#!/bin/bash

save_commands() {
    echo "CMD1 = $1" > Definitions
    echo "CMD2 = $2" >> Definitions
    echo "Commands saved."
}

top_menu() {
    echo "Select an option:"
    echo "1) Choose default commands"
    echo "2) Input commands manualy"
    echo "*) Quit"
}

sec_menu() {
    echo "Select a command pair:"
    echo "1) who | wc -l"
    echo "2) ls -l | head -n 4"
    echo "*) Quit"
}

main() {
    top_menu
    read opt1
    case $opt1 in
        1 )
            sec_menu
            read opt2
            case $opt2 in
                1)
                    save_commands "who" "wc -l"
                    ;;
                2)
                    save_commands "ls -l" "head -n 4"
                    ;;
                *)
                    echo "Bye!"
                    ;;
            esac
            ;;
        2 )
            echo "Enter command #1:"
            read CMD1
            echo "Enter command #2:"
            read CMD2
            save_commands "$CMD1" "$CMD2"
            ;;
        * ) echo "Bye!"
            ;;
    esac
}

main
