while getopts "ab:c" opt; do
    case $opt in
        a) echo "option -a" ;;
        b) echo "option -b with arg: $OPTARG" ;;
        c) echo "option -c" ;;
        \?) echo "usage: script [-a] [-b arg] [-c]"; exit 1 ;;
    esac
done

shift $((OPTIND - 1))
