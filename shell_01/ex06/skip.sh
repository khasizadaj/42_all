# The NR variable in awk represents the current line number.
ls -l | awk 'NR % 2 == 1'
