#!/bin/sh
filename=$(ls -t1 | head -1)
msg=$(head -n 2 $filename | tail -1)
echo $filename
echo $msg
git add $filename
echo "..........Before Committing.........."
git status
$(git commit -m \"$msg\")
echo "..........After Committing.........."
git status
# git push