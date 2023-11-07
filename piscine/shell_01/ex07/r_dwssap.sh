REMOVE_BETWEEN_LINES_CONDITIONS="NR >= ${FT_LINE1} && NR <= ${FT_LINE2}"
cat /etc/passwd |  awk 'NR % 2 == 1 || NR == 1' | sed -e 's/:.*//g' | rev | sort -r | awk "${REMOVE_BETWEEN_LINES_CONDITIONS}" | tr '\n' ',' | sed -e 's/,/, /g' | sed -e 's/, $/./'
