MusicBase is a music discovery website that allows users to enter any/all of the following to determine matching results: artist name, album name, song name, genre, date released (song) and more. The website first retrieves the user input through a text input box. The user is also expected to select what information they expect to see. Then, queries the database for information relating to the input.

Required software:
PHPMYADMIn
WAMP SERVER
Some text editor perfered Notepad++

Open PHPMYADMIN cretae folder called "musicbase"
Click "musicbase" and then click on SQL tab and copy the following notepad file in to the SQL command block and hit go it will create the album, song, song_link, user_comment and user_login.

File needed to create database found in folder "tableFinal":
open following file in notepad++ then copy the create statment and insert statment in PHPMYADMIN 
album_table.sql
song_table.sql
songlink_table.sql
user_comments.sql
userLogin.sql

Follow the regular process to download wampsever
Right click on the Wamp icon on the desktop and go to the properties and clickon the open file location folder. Then click on the folder called "www" and copy the folder from the zip file called "finalDP" into the www folder.
Now you can go to a web browser and type in "http://localhost/finalDP/finalDP/pages/" and voila project is running.
