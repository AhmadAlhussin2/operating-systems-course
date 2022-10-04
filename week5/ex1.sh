gcc publisher.c -o publisher
gcc subscriber.c -o subscriber
gnome-terminal -- ./publisher "$1"
if [ $1 -ge 3 ]; then
	gnome-terminal -- ./subscriber
	gnome-terminal -- ./subscriber
	gnome-terminal -- ./subscriber	
elif [ $1 -ge 2 ]; then
	gnome-terminal -- ./subscriber
	gnome-terminal -- ./subscriber
elif [ $1 -ge 1 ]; then
	gnome-terminal -- ./subscriber
fi
