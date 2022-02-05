# fzfclipboardmanager
Fast and lightweight clipboard manager

- Everything that once got on Clipboard is kept (aka clipboard persistence. Without a clipboard manager, sometimes     
                                                  a program close and what was copied to clipboard gets lost. fzfclipboard    
                                                  manager prevents that from happening, keeping the clipboard always ready     
                                                  to paste the last copied content).    
                                                  
- We use two modified versions of clipnotify (https://github.com/cdown/clipnotify), one to listen to clipboard content change,    
                                                  and the other to listen to clipboard getting empty.    

# How to use it    
- Start the daemon: fzfclipmanager -d     
- Set up a shortcut to open your favorite terminal emulator and run fzfclipmanager     

Keyboard shortcuts:    
<b>J</b>: for down     
<b>K</b>: for up    
<b>Enter</b>: to accept (= select entry)    
<b>Control + d</b>: to delete entry.    
