CREATE TABLE `User_Login` (
    `UserNo`    INT            UNSIGNED NOT NULL AUTO_INCREMENT,
    `UserName`  NVARCHAR (30)  NULL,
    `LoginName` NVARCHAR (10)  NOT NULL,
    `Password`  NVARCHAR (30)  NULL,
    `UserType`  NVARCHAR (30)  NULL,
    `Address`   NVARCHAR (95)  NULL,
    `UserGenre` NVARCHAR (15)  NULL,
    PRIMARY KEY CLUSTERED (`UserNo`),
    CONSTRAINT `AK_User_Login_Column` UNIQUE NONCLUSTERED (`LoginName`)
);



INSERT INTO `User_Login` (`UserName`, `LoginName`, `Password`, `UserType`, `Address`, `UserGenre`) VALUES
 ('Abdullah', 'Administer', '12345', 'Admin', '111 Taunton East Rd', 'Rock'),
('Prashaker', 'Prash', '9876', 'User', '1700 Simcoe St.', 'R&B'),
('John', 'JDoe', 'Doe122', 'User', NULL, NULL),
('Henry', 'MIA247', 'skd5546', 'User', '3 Ont Dr.', 'Rock'),
('Bob', 'Water54', '9876', 'User', '1700 Simcoe St.', NULL),
('Saurabh', 'Sam', 'hh12345', 'User', NULL, 'R&B'),
('Khaled', 'Bossman', 'theboss', 'User', NULL, NULL);