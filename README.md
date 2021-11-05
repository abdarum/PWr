# PWr

To clone repository, paste into terminal:
```
git clone --recurse-submodules -j8 https://github.com/abdarum/PWr.git
```

To add submodule:
```
git submodule add https://github.com/abdarum/ISM.git master/ISM
git add *
git commit -m "submodule added"
git push
```
`git submodule add` – This simply tells Git that we are adding a submodule. This syntax will always remain the same.
`https://github.com/abdarum/ISM.git` – This is the external repository that is to be added as a submodule. The exact syntax will vary depending on the setup of the Git repository you are connecting to. You need to ensure that you have the ability to clone the given repository.
`master/ISM` – This is the path where the submodule repository will be added to the main repository.

[Map Of Fields used in projects](MapOfFields.md)