set -e
set -o verbose
echo
echo ----------------------------------------------------------------------------------------------------------------
echo 
ls tests
petite -q tests/tests.scm --libdirs "tests/rough-draft-master/src/"

echo
echo ----------------------------------------------------------------------------------------------------------------
echo 
