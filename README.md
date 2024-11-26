## 不同目录名即为分支名

## 各个目录情况

- master
- luogu
- normal_work

## 如何创建新分支

新建的文件夹需要与远程仓库连接，并创建对应分支。

每个文件夹的初次操作流程如下：(本仓库远程命名为“Daily”)

1. 初始化

   > git init

2. 与远程仓库建立联系

   >git remote add Daily git@github.com:UNILkx/Daily.git

3. 本地切换分支

   > git checkout -b dir_name

   dir_name为文件夹名字

4. git add  初始化需要的文件

   > git add . / file_name

    看个人情况确定加文件

5. git commit 

   > git commit -m "add:xxxxx"

6. git push 并远程创建与本地

   > git push --set-upstream Daily dir_name
