## Day 3 - 21/02/26

Git & GitHub day. Finally got into version control properly. Messed around with basic workflow, local commands, remote stuff, and played a ton on https://learngitbranching.js.org/ – that site is gold for visualizing branches and commands. Super helpful.

### Core Git Concepts
- **Working directory** → **Staging area** → **Local repo** → **Remote repo**
- Changes happen in working dir, `git add` moves to staging, `git commit` saves to local repo, then push to remote.

### Basic Commands I Used
```bash
git init               # start a new repo
git status             # what's changed / staged?
git add .              # stage everything (or git add file.txt)
git add -A             # stage all including deletions
git commit -m "msg"    # commit with message
git log                # see commit history
git log --oneline      # compact view
```

### Branching
```bash
git branch             # list branches
git branch feature     # create branch
git checkout feature   # switch to it (or git switch feature now)
git checkout -b fix    # create + switch
git branch -d old      # delete branch
```

### Merge vs Rebase
- **Merge**: Combines histories, keeps branch commits visible → creates merge commit. Safe, preserves history.
  ```bash
  git checkout main
  git merge feature
  ```
- **Rebase**: Rewrites history to look linear, moves your commits on top of target branch. Cleaner history but dangerous if already pushed.
  ```bash
  git checkout feature
  git rebase main
  ```
- When to use? Merge for shared/public branches (team work), rebase for local feature branches before pushing.

### Remote Stuff (GitHub)
- **git clone** repo-url → copy remote repo to local
- **git fork** → your own copy on GitHub (for contributing to others' projects)
- **git remote -v** → see remotes
- **git push origin main** → send to remote
- **git fetch** → get remote changes without merging
- **git pull** → fetch + merge (git pull = git fetch + git merge)
- **git pull --rebase** → fetch + rebase instead

### Advanced-ish Ones I Tried
```bash
git stash              # save dirty changes temporarily
git stash pop          # bring them back
git cherry-pick <commit>  # apply one commit from another branch
git rebase -i HEAD~3   # interactive rebase last 3 commits (squash, edit, etc.)
```

### References & Flags Quick Hits
- HEAD~1 or HEAD^ → one commit back
- HEAD~2 → two back
- . → current dir
- \* → wildcard (e.g., git add *.cpp)
- -f → force (git push -f, dangerous!)
- --amend → change last commit message / add forgotten files

### Practice
Did local repo experiments: created branches, merged, rebased, stashed, cherry-picked. Then spent hours on Learn Git Branching – the visual tree thing makes everything click way better.
