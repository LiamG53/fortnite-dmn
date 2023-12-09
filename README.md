# fortnite-dmn
A universal way of communicating to kdm without any possible detection vectors hence the name Fortnite-DMN.
I created this project about a couple weeks ago while working on a external cheat and discovered this method. 
No i do not include the full init setup, however you need a brain. Its not hard to get NTDLL. 
Added a few things in the citations to show this is my work lol not anti-paste but a way for me to see whos using this.

# how-to-use
I put reading & base address function in this so maybe if this gets some stars I will implement the writing function to the public even though its already there.
Attach to a process with hiarchy privs, such as Fortnite/EOS/BE.

# future-changes
A unique way of implementing the shellcode to the function possibly a more stable one. 
Improve pd8 caching and possibly switch to pml4 entries.
Give public documenation to the Fortnite-Dmn-Signed and allow for others to add public commits.

# notes-before-using
I was given permission by my other developer friend before posting this yes this is the real working deal however its our first protype and not the latest version this version does not contain physical read/write. 

# updates
Releasing the full-working version tmw afternoon, containing the full physical extraction of NTDLL, and import finder. Also containg documentation for things and the physical image of the NTDLL file reader. 
Posting the virtual/physical fortnite-dmn versions which can be changed depending on you. Adding full support for updates/improvements plus the POC screenshots of it fully working with EOS running.
Posting Read/Write/Base/Get Guarded Region/Get PEB/Set Protect/ features as well for all games.

#errors-constant-improvements
Investigating an error where some Read calls return (out of bound) ptrs/values. May be do to a virtual memory error. Might release the full physical version idk.
