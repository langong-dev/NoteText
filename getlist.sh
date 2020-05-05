#!/bin/bash

getlist(){
  cat /etc/passwd | while read LINE  
  do
    list[$listcount] = $LINE
    listcount = $listcount + 1
  done
}
