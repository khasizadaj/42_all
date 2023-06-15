WD=$(pwd)
ROOT=$(git rev-parse --show-toplevel)
cd $ROOT
git ls-files --ignored --others --exclude-standard
cd $WD
