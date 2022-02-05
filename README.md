# fzfclipboardmanager
Fast and lightweight clipboard manager

- Everything that once got on Clipboard is kept (aka clipboard persistence. Without a clipboard manager, sometimes     
                                                  a program close and what was copied to clipboard gets lost. fzfclipboard    
                                                  manager prevents that from happening, keeping the clipboard always ready     
                                                  to paste the last copied content).    
                                                  
- We use two modified versions of clipnotify (https://github.com/cdown/clipnotify), one to listen to clipboard content change,    
                                                  and the other to listen to clipboard getting empty (both a precompiled and 
                                                  source code are available here).

# Dependencies
- fzf 
- xsel

# How to use it    
- Start the daemon: fzfclipmanager -d     
- Set up a shortcut to open your favorite terminal emulator and run fzfclipmanager     

Keyboard shortcuts:    
<b>J</b>: for down     
<b>K</b>: for up    
<b>Enter</b>: to accept (= select entry)    
<b>Control + d</b>: to delete entry.    

# Step by step instructions for beginners:
1. Install fzf and xsel and a terminal emulator like xterm for example:
    apt install fzf xsel xterm
2. Download the files fzfclipmanager, clipnotifychanged, clipnotifyempty and place then 
    inside a folder that is on your $PATH
3. Create a shortcut to run fzfclipmanager, for example "xterm -e fzfclipmanager"
4. Create a startup for the daemon "fzfclipmanager -d"
