if [ $# -ne 1 ] || [[ "$1" != "0" && "$1" != "1" ]]; then
    echo "Usage: $0 <DEBUG (0 lub 1)>"
    echo "Pomocnicze informacje(debug): ./compile.sh 1"
    echo "Bez pomocniczych informacji:  ./compile.sh 0"
    exit 1
fi
if [ -f har.e ]; then
    rm har.e
fi
make --quiet DEBUG=$1
