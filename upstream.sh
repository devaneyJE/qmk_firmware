#!/bin/bash

# Run to pull latest changes from QMK into personal fork

git checkout master
git fetch upstream
git pull upstream master
git push origin master
git checkout dev

