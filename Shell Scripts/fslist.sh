#!/bin/bash
if [ -f ./fsout.log ]; then
  rm fsout.log #Remove existing fsout.log
fi
warn='\033[1;33m' #Change font color to yellow
nc='\033[0m'      #Remove font color modifications
echo -e ${warn}This script will log a huge amount of text to the console!${nc}
echo Regular users do not have permission to read certain parts of the file system. This command needs to be run as root to fully list everything, which may require your password.
read -p 'Do you want to run as root? (y/n/c): ' choice
case $choice in
[yY]*)
  read -p 'Do you want color output as well? Note: using color output will not create a log file. (y/n): ' choice2
  case $choice2 in
  [yY]*)
    echo 'This may take a while.'
    sleep 2
    sudo dir --color=yes -AR /
    echo Done!
    ;;
  [nN]*)
    echo 'This may take a while.'
    sleep 2
    sudo dir --color=no -AR / 2>&1 | tee fsout.log
    echo Done! Output saved to fsout.log
    ;;
  esac
  ;;
[nN]*)
  read -p 'Do you want color output as well? Note: using color output will not create a log file. (y/n): ' choice2
  case $choice2 in
  [yY]*)
    echo 'This may take a while.'
    sleep 2
    dir --color=yes -AR /
    echo Done!
    ;;
  [nN]*)
    echo 'This may take a while.'
    sleep 2
    dir --color=no -AR /
    echo Done!
    ;;
  esac
  ;;
[cC]*) echo 'Cancelled.' ;;
*) exit
esac
if [ -f ./fsout.log ]; then #Only use nano if script was not cancelled.
  nano fsout.log
fi
