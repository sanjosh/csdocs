
# pull request number
# say pr-16578 is local branch

* git fetch origin pull/16578/head:pr-16578
* git fetch git@github.com:jboss/jboss-common-beans.git refs/pull/4/head

# fetch pull requests

```
[remote "origin"]
	fetch = +refs/heads/*:refs/remotes/origin/*
	url = git@github.com:joyent/node.git
	fetch = +refs/pull/*/head:refs/remotes/origin/pr/*
```

* git fetch origin
* git checkout pr/999

