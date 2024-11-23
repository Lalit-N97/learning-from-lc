#!/bin/sh
filename=$(ls -t1 | head -1)
msg=$(head -n 2 $filename | tail -1)
# echo $filename
# echo $msg
echo "..........Before Staging............"
git status
git add $filename
git commit -m " $msg " # added spaces around the variable message to avoid bash saying passing multiple 
# parameters to the commit command when a space separated commmit message is used
echo "..........After Committing.........."
git status
git push