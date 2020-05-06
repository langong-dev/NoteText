#!/bin/bash

fun(){
  clear
  echo " Please input this note's name: "
  read name < /dev/tty
  echo " Your New note's name is '"$name"'. Are you sure? [Y]es, [N]o"
  read ts;
  if [[ $ts == "n" || $ts == "N" ]];
  then
    fun
  fi
}

fun
echo $name >> ~/LanGongNoteText/list
echo -n > ~/LanGongNoteText/$name.md
