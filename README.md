# fzfclipboardmanager
Fast and lightweight clipboard manager

- Everything that once got on Clipboard is kept (aka clipboard persistence. Without a clipboard manager, sometimes     
                                                  a program close and what was copied to clipboard gets lost. fzfclipboard    
                                                  manager prevents that from happening, keeping the clipboard always ready     
                                                  to paste the last copied content).    
                                                  
- We use a modified version of clipnotify (https://github.com/cdown/clipnotify), to listen to clipboard content change,    
                                                  and to check when clipboard get empty (both precompiled and the source 
                                                  are available here).

# Dependencies
- fzf 
- xsel

# How to use it    
- Start the daemon: fzfclipmanager -d     
- Stop the daemon: fzfclipmanager -q
- Set up a shortcut to open your favorite terminal emulator and run fzfclipmanager     

Keyboard shortcuts:    
<b>J</b>: for down     
<b>K</b>: for up    
<b>Enter</b>: to accept (= select entry)    
<b>Control + d</b>: to delete entry.    

# Step by step instructions for beginners:
1. Install fzf and xsel and a terminal emulator like st for example on Debian based systems:
    apt install fzf xsel st
2. Download the files fzfclipmanager ane clipnotify and place them inside a folder in your ${PATH}
3. Create a shortcut to run fzfclipmanager, for example "st fzfclipmanager"
4. Create a startup for the daemon "fzfclipmanager -d"
