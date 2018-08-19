
# Basic

## config

* git config --global color.ui auto
* git config --global user.name "name"
* git config --global user.email "email"

## branches containing git tag
git branch -r --contains

## head
http://stackoverflow.com/questions/2304087/what-is-head-in-git?rq=1

## reset
http://stackoverflow.com/questions/2530060/can-you-explain-what-git-reset-does-in-plain-english?rq=1

## add existing files only
git add -u -p

## how to read output of git diff

"git diff <old> <new>" equiv to "diff -u old new"

```--- shows lines in 1st branch
+++ shows lines in 2nd branch
```

```If you set diff.mnemonicPrefix configuration variable to true, in place of a/ and b/ prefixes in this two-line header you can have instead c/, i/, w/ and o/ as prefixes, respectively to what you compare
```

``` minus signs shows lines in the a/ version but missing from the b/ version; and plus signs shows lines missing in a/ but present in b/ (in my case --- means deleted lines and +++ means added lines in b/ and this the file in the working directory)
```

http://stackoverflow.com/questions/2529441/how-to-read-the-output-from-git-diff

## Tags

### delete old tag from remote repo

git push origin :refs/tags/${tagname}

### move tag to latest commit in this branch

git tag -fa ${tagname}

### push tag to remote repo

git push -f --tags

## history 

git log -p

## clean all

git clean -d -f -x

## Submodules 

## Bare repo

http://stackoverflow.com/questions/2199897/how-to-convert-a-git-repository-from-normal-to-bare

# Remote

## shallow clone

git clone --depth 10 https://github.com

git archive --remote https://github.com/some.git master --format=tar.gz | tar xfvz -

## create remote git branch

http://stackoverflow.com/questions/1519006/how-do-you-create-a-remote-git-branch?rq=1

## delete remote branch

git push origin --delete <branchname>

## get github repo size

curl https://api.GitHub.com/repos/cloudera/impala | egrep "\"size\""

## update list of branches on remote

git remote update origin --prune

## disable push

git remote set-url --push origin no_push

## which branches are tracking

http://stackoverflow.com/questions/4950725/how-do-i-get-git-to-show-me-which-branches-are-tracking-what?rq=1

## ssh

### test ssh

ssh -T git@github.com

https://help.github.com/articles/checking-for-existing-ssh-keys/

https://help.github.com/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent/

### to start ssh agent
eval "$(ssh-agent -s)"

### to test exported keys

ssh-add -l

## Clone a single dir

### for master, use "trunk"

svn export <repo>/trunk/<folder>

svn export https://github.com/lodash/lodash/trunk/docs

### for another branch

svn export https://github.com/lodash/lodash/branches/<branchname>/<foldername>

