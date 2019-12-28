# 1. The libs in the blacklight.c in others files

```
blacklight.c <- bar and panels, window manager, multidisplay manager, workspace manager
   |
   +-> blacklight.c, bar.c, client.c, monitor.c, workspace.c
        |             |       |         |           |
        |             |       |         |           +-> workspace manager
        |             |       |         +-> multidisplay manager
        |             |       +-> window manager
        |             +-> bar and panels
        +-> libs manager
```

[ ] - monitor.c
[ ] - client.c
[ ] - bar.c
[ ] - workspace.c

# 2. A fake window array to insert especial windows.

```
B - bars - panels - etc.
W - normal windows

+----------------+
|  ____________  |
| |            | |
| |            | |
| |      W     |B|
| |            | |
| +------------+ |
|________________|
```
