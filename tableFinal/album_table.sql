CREATE TABLE `Album` (
    `AlbumNo`      INT            UNSIGNED NOT NULL AUTO_INCREMENT,
    `AlbumName`    NVARCHAR (150) NOT NULL,
    `AlbumArtist`  NVARCHAR (50)  NOT NULL,
    `AlbumLength`  NVARCHAR (255) NULL,
    `AlbumRating`  NVARCHAR (255) NULL,
    `AlbumPicture` NVARCHAR (255) NULL,
    `ReleaseYear`  NVARCHAR (255) NULL,
    `Genre`        NVARCHAR (255) NULL,
    PRIMARY KEY (`AlbumNo`)
);


INSERT INTO `Album` (`AlbumName`, `AlbumArtist`, `AlbumLength`, `AlbumRating`, `AlbumPicture`, `ReleaseYear`, `Genre`) VALUES ('1989', 'Taylor Swift', '48:41', '3', 'http://upload.wikimedia.org/wikipedia/en/thumb/f/f6/Taylor_Swift_-_1989.png/220px-Taylor_Swift_-_1989.png', '2014', 'Pop'),
('Cole World', 'J Cole', '57:43', '4', 'http://upload.wikimedia.org/wikipedia/en/thumb/7/76/ColeWorld.jpeg/220px-ColeWorld.jpeg', '2011', 'Hip Hop'),
('Nothing Was The Same', 'Drake', '59:22', '4', 'http://upload.wikimedia.org/wikipedia/en/thumb/d/d0/Nothing_Was_the_Same_cover_1.png/220px-Nothing_Was_the_Same_cover_1.png', '2013', 'Hip Hop'),
('The Marshall Mathers LP 2', 'Eminem', '78:13', '4', 'http://upload.wikimedia.org/wikipedia/en/thumb/8/87/The_Marshall_Mathers_LP_2.png/220px-The_Marshall_Mathers_LP_2.png', '2013', 'Rap'),
('Night Visions', 'Imagine Dragons', '42:10', '3', 'http://upload.wikimedia.org/wikipedia/en/thumb/3/3f/Night_Visions_Album_Cover.jpeg/220px-Night_Visions_Album_Cover.jpeg', '2012', 'Rock'),
('Watch The Throne', 'Kanye West', '46:02', '5', 'http://upload.wikimedia.org/wikipedia/en/thumb/e/ee/Watch_The_Throne.jpg/220px-Watch_The_Throne.jpg', '2011', 'Hip Hop'),
('Camp', 'Childish Gambino', '56:06', '5', 'http://upload.wikimedia.org/wikipedia/en/thumb/e/e2/Childish-gambino-camp.jpg/220px-Childish-gambino-camp.jpg', '2011', 'R&B'),
('Born Sinner', 'J Cole', '59:47', '5', 'http://upload.wikimedia.org/wikipedia/en/thumb/2/21/J_Cole_Born_Sinner1.jpg/220px-J_Cole_Born_Sinner1.jpg', '2013', 'Hip Hop');