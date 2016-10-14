//Find all the songs that certain artist have work on 
CREATE VIEW QUERY1
AS SELECT AlbumPicture,SongName,AlbumName,a.AlbumArtist,SongContributingArtist,SongYoutubeLink,SongMP3Download
FROM Album AS a INNER JOIN Song As s ON a.AlbumNo=s.AlbumNo
INNER JOIN Song_Link AS sl ON s.SongNo=sl.SongNo
WHERE s.SongContributingArtist='TLC' OR a.AlbumArtist='J Cole'

//Find the album created in specfic year
CREATE VIEW QUERY2
AS SELECT AlbumPicture,AlbumName,AlbumArtist,AlbumLength,AlbumRating,Genre,ReleaseYear
FROM Album
WHERE ReleaseYear= ANY(SELECT ReleaseYear
					FROM Album
			       WHERE ReleaseYear='2013')
//Find the comment by the user
CREATE VIEW QUERY3
AS SELECT Comment, s.SongName
FROM User_Comment AS uc INNER JOIN Song AS s ON uc.SongNo=s.SongNo
WHERE uc.UserNo = (SELECT UserNo
			FROM User_Login	
			WHERE LoginName='Prashaker')

//Find the Song that that have high raing in all the year
CREATE VIEW QUERY4
AS SELECT SongName, SongLength, s.SongArtist, SongsRating,SongReleaseDate
FROM Song s 
WHERE  SongReleaseDate= (SELECT SongReleaseDate FROM Song s1 WHERE s1.SongReleaseDate=s.SongReleaseDate AND (SongsRating Between 3 AND 5) GROUP BY SongReleaseDate)
// Find the specfic song with the comments
CREATE VIEW QUERY5
AS SELECT LoginName, Comment
FROM User_Comment AS uc
WHERE EXISTS(Select* FROM Song WHERE SongName='Murder To Excellence' AND SongNo=uc.SongNo)

//Find all the songs in the certain album
CREATE VIEW QUERY6
AS 
SELECT SongName, SongLength, AlbumName, s.SongArtist, SongsRating,SongReleaseDate
FROM Song s FULL JOIN Album a
ON s.AlbumNo=a.AlbumNo
WHERE a.AlbumName='Born Sinner'
//
CREATE VIEW QUERY7
AS SELECT SongName, SongArtist, SongLength
FROM Song
WHERE SongContributingArtist='Jay Z'
INTERSECT
(SELECT SongName, SongArtist, SongLength FROM Song WHERE SongReleaseDate='2013')

//Find the song in specfic genre
CREATE VIEW QUERY8
AS SELECT SongName, AlbumName, a.AlbumArtist, SongLength
FROM Song s, Album a
WHERE s.SongGenre='Hip Hop' AND s.AlbumNo=a.AlbumNo

//Find the top song in the specfic genre
CREATE VIEW QUERY9
AS SELECT SongName,AlbumName,s.SongArtist,SongsRating,SongLength
FROM Song s, Album a
WHERE((s.SongsRating BETWEEN 3 AND 5 ) AND s.SongGenre='Hip Hop')
AND s.AlbumNo=a.AlbumNo
//Find the song link
CREATE VIEW QUERY10
AS SELECT *
FROM Song_Link AS sl
WHERE EXISTS(SELECT SongNo FROM Song WHERE SongName='Rise and Shine' AND sl.SongNo=SongNo)