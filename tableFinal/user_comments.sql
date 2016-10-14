CREATE TABLE `User_Comment` (
    `CommentNo` INT            UNSIGNED NOT NULL AUTO_INCREMENT,
    `UserNo`    INT            UNSIGNED NOT NULL,
    `LoginName` NVARCHAR (10)  NOT NULL,
    `SongNo`    INT            UNSIGNED NULL,
    `AlbumNo`   INT            UNSIGNED NULL,
    `Comment`   NVARCHAR (255) NULL,
    PRIMARY KEY CLUSTERED (`CommentNo`),
    CONSTRAINT `FK_User_Comment_Song` FOREIGN KEY (`SongNo`) REFERENCES `Song` (`SongNo`),
    CONSTRAINT `FK_User_Comment_User_Login` FOREIGN KEY (`UserNo`) REFERENCES `User_Login` (`UserNo`),
    CONSTRAINT `FK_User_Comment_User_Login1` FOREIGN KEY (`LoginName`) REFERENCES `User_Login` (`LoginName`),
    CONSTRAINT `FK_User_Comment_Album` FOREIGN KEY (`AlbumNo`) REFERENCES `Album` (`AlbumNo`)
);



INSERT INTO `User_Comment` (`UserNo`, `LoginName`, `SongNo`, `AlbumNo`, `Comment`) VALUES (3, 'JDoe', 14, 1, 'I heard this on the radio... love it!'),
(6, 'Sam', 61, 7, 'Catchy song but didnt like the beat.'),
(6, 'Sam', 18, 1, 'Ew taylor swift, dissapointing.'),
(7, 'Bossman', 14, 1, 'YAY TAYLOR SWIFT!!!'),
(2, 'Prash', 66, 8, 'Kinda like the remix better!'),
(5, 'Water54', 37, 5, 'Mehhhh'),
(7, 'Bossman', 5, 2, 'Could have been better I would say 4/5.'),
(7, 'Bossman', 54, 7, 'Childish Gambino is pretty good'),
(5, 'Water54', 23, 4, 'Should have been in an album...'),
(6, 'Sam', 43, 6, 'Good collaboration song'),
(6, 'Sam', 41, 5, 'Sucks rap > rock'),
(2, 'Prash', 70, 8, 'Best album of 2013 would recommend to others');
