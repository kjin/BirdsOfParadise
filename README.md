# BirdsOfParadise

A framework (currently) for a 3D shmup video game. Written in C++ with cocos2d-x (http://www.cocos2d-x.org/).

<h2>Build instructions</h2>

<p>1. Open a git shell and navigate to the desired directory</p>
<p>2. Clone this repository (<b>git clone https://github.com/kjin/BirdsOfParadise.git</b>)</p>
<p>3. Enter new directory (<b>cd BirdsOfParadise</b>)</p>
<p>4. Get submodule components (<b>git submodule init; git submodule update</b>). This should get you cocos2d-x</p>
<p>5. Get cocos2d-x dependencies (<b>cd cocos2d; python ./download-deps.py</b>)</p>

<h3>Win32 - Windows only</h3>
<sub>Prerequisites: Visual Studio 2013, Git, Python 2.7</sub>
<p>6. In original directory, open proj.win32/BirdsOfParadise.sln in VS2013</p>
<p>7. Build & Run!</p>

<h3>Mac - OSX only; not recently tested</h3>
<sub>Prerequisites: Xcode + developer tools, Python 2.7</sub>
<p>6. In original directory, open proj.win32/BirdsOfParadise.sln in Xcode</p>
<p>7. Switch to BirdsOfParadise-mac project; build & Run! - Note: Project file has not been updated recently, so files may need to be re-added to project</p>

<h3>Android - Windows/OSX/Linux; not tested yet</h3>
<sub>Prerequisites: Android phone, compatible USB cord, cygwin, Android SDK, Android NDK, Eclipse, ADT plugin for Eclipse, Python 2.7</sub>

<h3>Win8.1, Windows Phone, iOS, Linux</h3>
Don't even bother with these right now
