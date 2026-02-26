CHECKER="./tips/checker_linux"

# Colors
RED='\033[0;31m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
BOLD='\033[1m'
RESET='\033[0m'

# Push_swap executable path
PUSH_SWAP="./push_swap"

pause() {
    printf "${BOLD}${RESET}Press Enter to continue...${RESET}"
    read _
	clear
}

run_checker() {
    local move="$1"
    local args="$2"
    local res=""

    echo "${CYAN}$move | $CHECKER $args${BLUE}"
	( echo "$move" | $CHECKER $args ) > res.txt
	res=$( cat res.txt )
	echo "${BLUE}$res"
}

run_checker "$( echo "sa pb rrr " | tr ' ' '\n' )" "2147483648"
run_checker "$( echo "sa pb rrr " | tr ' ' '\n' )" "2147483648 7 8"
pause

run_checker "$( echo "sa pb rrr " | tr ' ' '\n' )" "0 9 1 8 2 7 3 6 4 5"
pause

run_checker "$( echo "pb ra pb ra sa ra pa pa " | tr ' ' '\n' )" "0 9 1 8 2"
pause

run_checker "$( echo "ra ra pb ra pb ra pb ra ra pb ra pb pb rb rrb pa rb rrb pa rb rrb pa rb pa rb rrb pa pa " | tr ' ' '\n' )" "0 9 1 8 2 5"
pause
