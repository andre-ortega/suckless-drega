#! /bin/sh

# Terminate already running bar instances
killall polybar

# Wait untill the processes have been shut down
while pgrep -u $UID -x polybar >/dev/null; do sleep 1; done

# Launch bar for primary monitor
MONITOR=eDP-1 polybar left --config=$HOME/.config/polybar/config.ini &
MONITOR=eDP-1 polybar center --config=$HOME/.config/polybar/config.ini &
MONITOR=eDP-1 polybar right --config=$HOME/.config/polybar/config.ini &

# Launch bar for secondary monitor
MONITOR=HDMI-1 polybar secondary-left --config=$HOME/.config/polybar/config.ini &
MONITOR=HDMI-1 polybar secondary-center --config=$HOME/.config/polybar/config.ini &
MONITOR=HDMI-1 polybar secondary-right --config=$HOME/.config/polybar/config.ini &
