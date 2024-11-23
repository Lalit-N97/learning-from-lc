#!/bin/sh
filename=$(ls -t1 | head -1)
msg=$(head -n 2 $filename | tail -1)
echo $filename
echo $msg
echo "..........Before Staging.........."
git add $filename
git status
echo "..........After Staging.........."
git status
git commit -m '$msg'
echo "..........After Committing.........."
git status
# git push