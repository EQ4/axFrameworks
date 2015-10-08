#!/bin/bash

function commit_submodules
{

        for dir in $(find modules/ -type d -maxdepth 1); do
                cd -v $dir;
                git add .;
                git commit -m "$1";
                git push;
                cd -v -;
        done
}

function clean_history
{
        for dir in $(find modules/ -type d -maxdepth 1); do
                cd -v $dir;
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
                cd -v -;
        done
}

if [ "$1" == "clean_history" ]; then
        clean_history;

elif [ "$1" == "commit_submodules" ]; then
        commit_submodules "$2";
fi
