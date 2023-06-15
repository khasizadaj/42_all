find . -name "*.sh"  -type f -printf "%f\n" | sed -e "s/\.sh//g"
