CREATE TABLE `Song_Link` (
    `SongNo`          INT            UNSIGNED NOT NULL,
    `SongYouTubeLink` NVARCHAR (255) NULL,
    `SongMP3Download` NVARCHAR (255) NULL,
    PRIMARY KEY CLUSTERED (`SongNo` ASC),
    CONSTRAINT `FK_Song_Link_Song` FOREIGN KEY (`SongNo`) REFERENCES `Song` (`SongNo`)
);


INSERT INTO `Song_Link` (`SongNo`, `SongYouTubeLink`, `SongMP3Download`) VALUES (1, N'https://www.youtube.com/watch?v=Jz4ZNlLFp1Q', NULL),
(2, N'https://www.youtube.com/watch?v=sKt1QwCCMl0', NULL),
(3, N'https://www.youtube.com/watch?v=qL3aCNM9Mrc', NULL),
(4, N'https://www.youtube.com/watch?v=y-vQ_VsTkn0', NULL),
(5, N'https://www.youtube.com/watch?v=vsdLE_bgM3I', NULL),
(6, N'https://www.youtube.com/watch?v=22st8ORI8RU', NULL),
(7, N'https://www.youtube.com/watch?v=fwux1A5hBdQ', NULL),
(8, N'https://www.youtube.com/watch?v=-dyPeGDeS3o', NULL),
(9, N'https://www.youtube.com/watch?v=kj8DQ_mT7B8', NULL),
(10, N'https://www.youtube.com/watch?v=F7sQNhQsv1M', NULL),
(11, N'https://www.youtube.com/watch?v=CjNiTUhfu5g', NULL),
(12, N'https://www.youtube.com/watch?v=lmUDfzJTKgQ', NULL),
(13, N'https://www.youtube.com/watch?v=nfWlot6h_JM', NULL),
(14, N'https://www.youtube.com/watch?v=zpwCWesWQIY', NULL),
(15, N'https://www.youtube.com/watch?v=PfDxWIN7LH0', NULL),
(16, N'https://www.youtube.com/watch?v=PVAfR3QjFKo', NULL),
(17, N'https://www.youtube.com/watch?v=NWIhaqq2NUw', NULL),
(18, N'https://www.youtube.com/watch?v=uJvTpE2fSo8', NULL),
(19, N'https://www.youtube.com/watch?v=5knXrTPLSlk', NULL),
(20, N'TESTING', NULL),
(21, N'https://www.youtube.com/watch?v=6o9dXLNuXic', NULL),
(22, N'https://www.youtube.com/watch?v=O0lf_fE3HwA', NULL),
(23, N'https://www.youtube.com/watch?v=rSOzN0eihsE', NULL),
(24, N'https://www.youtube.com/watch?v=BZy1f0Tl7OM', NULL),
(25, N'https://www.youtube.com/watch?v=xfrRLdUMhqA', NULL),
(26, N'https://www.youtube.com/watch?v=lF7C8NFzAGQ', NULL),
(27, N'https://www.youtube.com/watch?v=CccnAvfLPvE', NULL),
(28, N'https://www.youtube.com/watch?v=Wo1P_OKRtcQ', NULL),
(29, N'https://www.youtube.com/watch?v=T20kz4tLbFM', NULL),
(30, N'https://www.youtube.com/watch?v=7bDLIV96LD4', NULL),
(31, N'https://www.youtube.com/watch?v=EHkozMIXZ8w', NULL),
(32, N'https://www.youtube.com/watch?v=ItnJ0G8tINE', NULL),
(33, N'https://www.youtube.com/watch?v=NlmezywdxPI', NULL),
(34, N'https://www.youtube.com/watch?v=88zFzKk3xMM', NULL),
(35, N'https://www.youtube.com/watch?v=71xeMTazmMo', NULL),
(36, N'https://www.youtube.com/watch?v=w5tWYmIOWGk', NULL),
(37, N'https://www.youtube.com/watch?v=6RVxzeBiBJU', NULL),
(38, N'https://www.youtube.com/watch?v=1Yr683VLxes', NULL),
(39, N'https://www.youtube.com/watch?v=TKtPXO5iEnA', NULL),
(40, N'https://www.youtube.com/watch?v=mWRsgZuwf_8', NULL),
(41, N'https://www.youtube.com/watch?v=ktvTqknDobU', NULL),
(42, N'https://www.youtube.com/watch?v=9Fhr9igHBV8', NULL),
(43, N'https://www.youtube.com/watch?v=3yn5qj1pCj4', NULL),
(44, N'https://www.youtube.com/watch?v=d2mBK9LsKf4', NULL),
(45, N'https://www.youtube.com/watch?v=mx34fi1dodU', NULL),
(46, N'https://www.youtube.com/watch?v=_uk4fA5jMDI', NULL),
(47, N'https://www.youtube.com/watch?v=APio7f0vvJk', NULL),
(48, N'https://www.youtube.com/watch?v=s8S5PN1FnFk', NULL),
(49, N'https://www.youtube.com/watch?v=BoEKWtgJQAU', NULL),
(50, N'https://www.youtube.com/watch?v=gG_dA32oH44', NULL),
(51, N'https://www.youtube.com/watch?v=3MIVKGn9i0s', NULL),
(52, N'https://www.youtube.com/watch?v=FJt7gNi3Nr4', NULL),
(53, N'https://www.youtube.com/watch?v=VCi755xr030', NULL),
(54, N'https://www.youtube.com/watch?v=eDoC90RpjjE', NULL),
(55, N'https://www.youtube.com/watch?v=J-vUJx8swoU', NULL),
(56, N'https://www.youtube.com/watch?v=fLxxxXsHXZM', NULL),
(57, N'https://www.youtube.com/watch?v=xv_d2RUDMag', NULL),
(58, N'https://www.youtube.com/watch?v=LkWpURhvN3E', NULL),
(59, N'https://www.youtube.com/watch?v=f7plhrsQSEE', NULL),
(60, N'https://www.youtube.com/watch?v=dFVxGRekRSg', NULL),
(61, N'https://www.youtube.com/watch?v=wCPThoaNDoo', NULL),
(62, N'https://www.youtube.com/watch?v=qL1B_r9nC9k', NULL),
(63, N'https://www.youtube.com/watch?v=pHHWPTs1zxg', NULL),
(64, N'https://www.youtube.com/watch?v=mXahuQhadV4', NULL),
(65, N'https://www.youtube.com/watch?v=fR3ITE967mM', NULL),
(66, N'https://www.youtube.com/watch?v=bLF39513uwM', NULL),
(67, N'https://www.youtube.com/watch?v=fzzMOMkjm8A', NULL),
(68, N'https://www.youtube.com/watch?v=N-XsGSXUjhI', NULL),
(69, N'https://www.youtube.com/watch?v=F6jKKVwqRug', NULL),
(70, N'https://www.youtube.com/watch?v=jYdaQJzcAcw', NULL),
(71, N'https://www.youtube.com/watch?v=qvgO9Gp_rTE', NULL),
(72, N'https://www.youtube.com/watch?v=QkYEhCrevrg', NULL),
(73, N'https://www.youtube.com/watch?v=7AjD7nKiUQ4', NULL),
(74, N'https://www.youtube.com/watch?v=Y2rd566LRWw', NULL);
