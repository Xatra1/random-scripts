#!/bin/bash
if [ -f ./fsout.log ]; then
  echo Removing existing log files...
  rm fsout.log #Remove existing fsout.log
  rm fserr.log #Remove existing fserr.log if fsout.log is found
fi
red='\033[1;31m' #Change font color to red
yel='\033[1;33m' #Change font color to yellow
nc='\033[0m'     #Remove font color modifications
echo -e ${red}'WARN: This script logs a LOT of text (possibly millions of lines) to the console.'${nc}
echo 'Regular users do not have permission to read certain parts of the file system. This command needs to be run as root to fully list everything, which may require your password.'
read -p 'Do you want to run as root? (y/n/c): ' choice
case $choice in
[yY]*)
  echo -e ${yel}'Note: using color output will not create a log file.'${nc}
  read -p 'Do you want color output as well? (y/n/c): ' choice2
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
    sudo dir --color=no -AR / 2>fserr.log | tee fsout.log
    echo 'Done! Output saved to fsout.log'
    echo 'Any errors that may have occurred during the process are listed in fserr.log'
    ;;
  [cC]*) echo 'Cancelled.' ;;
  *) exit ;;
  esac
  ;;
[nN]*)
  echo -e ${yel}'Note: using color output will not create a log file.'${nc}
  read -p 'Do you want color output as well? (y/n/c): ' choice2
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
    dir --color=no -AR / 2>fserr.log | tee fsout.log
    echo 'Done! Output saved to fsout.log'
    echo 'Any errors that may have occurred during the process are listed in fserr.log'
    ;;
  [cC]*) echo 'Cancelled.' ;;
  *) exit ;;
  esac
  ;;
[cC]*) echo 'Cancelled.' ;;
*) exit ;;
esac
if [ -f ./fsout.log ]; then #Only ask to use nano if script was not cancelled.
  echo -e ${yel}'Once nano opens, you can close out of fsout.log and get to fserr.log by pressing Ctrl+X'${nc}
  read -p 'Do you want to open the newly created files using nano? (y/n): ' choice
  case $choice in
  [yY]*)
    clear
    nano fsout.log fserr.log
    ;;
  [nN]*)
    echo Process exited with status code $?
    ;;
  esac
fi
