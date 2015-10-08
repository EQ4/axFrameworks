#!/bin/bash

function echo_currDir
{
        echo -e "\n###\nProcessing $(pwd) \n###\n";
}

function commit_submodules
{

        for dir in $(find modules/ -type d -maxdepth 1); do
                cd $dir;
                echo_currDir;
                git add .;
                git commit -m "$1";
                git push;
                cd -;
        done
}

function clean
{
        git ls-files > keep-these.txt;
        git filter-branch --force --index-filter \
                  "git rm  --ignore-unmatch --cached -qr . ; \
                    cat $PWD/keep-these.txt | xargs git reset -q \$GIT_COMMIT --" \
                      --prune-empty --tag-name-filter cat -- --all;
        rm -rf .git/refs/original/;
        git reflog expire --expire=now --all;
        git gc --prune=now;
        git gc --aggressive --prune=now;
        rm keep-these.txt;
}

function clean_history
{
        for dir in $(find modules/ -type d -maxdepth 1); do
                cd $dir;
                echo_currDir;
                clean;
                cd -;
        done
        echo_currDir;
        clean;
}

if [ "$1" == "clean_history" ]; then
        clean_history;

elif [ "$1" == "commit_submodules" ]; then
        commit_submodules "$2";
fi
