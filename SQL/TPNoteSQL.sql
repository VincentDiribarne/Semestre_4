--Question 1
--CREATE OR ALTER PROCEDURE question1
--    @Date DATE
--AS
--BEGIN
--    SELECT Rubrique.Nom, @Date AS 'Date', COUNT(*) AS NbVisites
--    FROM Rubrique INNER JOIN Article ON Rubrique.Identifiant=Article.IdentifiantRubrique 
--	INNER JOIN Visite ON Article.Identifiant=Visite.IdentifiantArticle
--    WHERE Visite.DateHeureDebut LIKE CONCAT(@Date, '%')
--    GROUP BY Rubrique.Nom, Rubrique.Identifiant
--END
--GO

--exec q1 '23/06/2013';

--Question 2
--Récupérer le nom des rédacteurs ayant créé des articles visités le 23/06/2013 (afficher le nom du rédacteur, la date demandée, le nombre de visites).
--Fournir une date en paramètre de la procédure stockée
--CREATE OR ALTER PROCEDURE question2
--    @Date DATETIME2
--AS
--BEGIN
--    SELECT Utilisateur.Nom, @Date, COUNT(*) AS NbVisites
--    FROM Utilisateur
--    INNER JOIN Article ON Article.IdentifiantUtilisateur = Utilisateur.Identifiant
--    WHERE Article.DatePublication <= @Date
--    GROUP BY Utilisateur.Nom, Utilisateur.Identifiant
--END
--GO

--exec q2 '23/06/2013';

--Question 3
--CREATE OR ALTER PROCEDURE question3
--    @IdentifiantArticle INT,
--    @ArticleSize INT OUTPUT
--AS
--BEGIN
--    SET @ArticleSize = 0;
--    SELECT @ArticleSize = @ArticleSize + Media.Taille
--    FROM Media
--    WHERE Media.IdentifiantArticle = @IdentifiantArticle;
--	RETURN;
--END
--GO
--DECLARE @size int; 
--exec q3 4, @size OUTPUT;
--print(@size);

--Question 4
--Réaliser une procédure stockée qui affiche tous les articles ayant un poids (même principe que précédemment) supérieur à une valeur fourni en paramètre (en Ko)
--CREATE OR ALTER PROCEDURE question4
--    @Poids INT
--AS
--BEGIN
--    SELECT Article.Identifiant, Article.Titre, Article.DatePublication, Article.DescriptionCourte, Article.DescriptionLongue, Taille
--    FROM Article INNER JOIN Media ON Article.Identifiant = Media.IdentifiantArticle
--    WHERE Taille > @Poids
--END
--GO

--EXEC q4 40000;

--Question 5
--CREATE OR ALTER PROCEDURE question5(@annee INT)
--AS
--BEGIN
--    SELECT Rubrique.nom, Article.titre, COUNT(Article.Identifiant) AS nbVisites, Visite.DateHeureDebut
--    FROM Rubrique
--        INNER JOIN Article ON Rubrique.Identifiant = Article.IdentifiantRubrique
--        INNER JOIN Visite ON Visite.Identifiant = Article.IdentifiantRubrique
--    WHERE YEAR(Visite.DateHeureDebut) = @annee
--    GROUP BY Rubrique.nom, Article.titre, Visite.DateHeureDebut
--END
--GO

--exec q5 '2013';


--Question 6
--CREATE OR ALTER PROCEDURE question6
--    @IdentifiantArticle INT,
--    @NbVisites INT OUTPUT
--AS
--BEGIN
--    SET @NbVisites = 0;
--    SELECT @NbVisites = COUNT(*)
--    FROM Visite
--    WHERE Visite.IdentifiantArticle = @IdentifiantArticle;
--	RETURN;
--END
--GO

--DECLARE @size int; 
--exec q6 1, @size OUTPUT;
--print(@size);

--Question 7
--CREATE OR ALTER TRIGGER question7 ON Media
--AFTER INSERT 
--AS
--BEGIN 
--SET NOCOUNT ON
--	IF EXISTS(SELECT INSERTED.Taille FROM INSERTED WHERE (inserted.IdentifiantTypeMedia = 1 AND inserted.Taille >= 50000))
--		BEGIN
--			ROLLBACK TRANSACTION
--		END

--	IF EXISTS(SELECT INSERTED.Taille FROM INSERTED WHERE (inserted.IdentifiantTypeMedia = 2 AND inserted.Taille >= 5000))
--		BEGIN	
--			ROLLBACK TRANSACTION
--		END

--	IF EXISTS(SELECT INSERTED.Taille FROM INSERTED WHERE (inserted.IdentifiantTypeMedia = 3 AND inserted.Taille >= 1000))
--		BEGIN	
--			ROLLBACK TRANSACTION
--		END 
--END
--GO

--INSERT INTO Media(Titre, URL, Taille, IdentifiantArticle, IdentifiantTypeMedia, DescriptionCourte) VALUES
--('Bande Annonce', 'ba_stalker.avi', 1001, 7, 3, 
--'In tandem qua germanum spe Caesar eum est multis contemplans haerebat introisset venire existimabat se suam ut quid cum se.'),
--('Bande Annonce', 'ba_stalker.avi', 1000, 7, 2, 
--'In tandem qua germanum spe Caesar eum est multis contemplans haerebat introisset venire existimabat se suam ut quid cum se.'),

--Question 9
--CREATE OR ALTER TRIGGER question8 ON Visite
--AFTER INSERT 
--AS
--BEGIN 
--SET NOCOUNT ON
--	IF EXISTS(SELECT INSERTED.Identifiant FROM INSERTED INNER JOIN Article ON Inserted.IdentifiantArticle=Article.Identifiant INNER JOIN Rubrique ON Article.IdentifiantRubrique=Rubrique.Identifiant WHERE Rubrique.Identifiant = 2 OR Rubrique.Identifiant = 3)
--		BEGIN
--			ROLLBACK TRANSACTION
--		END 
--END
--GO

--INSERT INTO Visite(AdresseIP, Pays, Ville, Navigateur, Systeme, DateHeureDebut, DateHeureFin, IdentifiantArticle) VALUES
--('127.0.0.65', 'FRANCE', 'Paris', 'IE', 'Win7', '12-10-13 12:33:00', '12-10-13 12:35:00', 5)

--INSERT INTO Visite(AdresseIP, Pays, Ville, Navigateur, Systeme, DateHeureDebut, DateHeureFin, IdentifiantArticle) VALUES
--('127.0.0.65', 'FRANCE', 'Paris', 'IE', 'Win7', '12-10-13 12:33:00', '12-10-13 12:35:00', 1)

--Question 10
--CREATE SCHEMA schema_article
--GO

--CREATE TABLE schema_article.Rubrique
--	(
--	Identifiant TINYINT PRIMARY KEY NOT NULL IDENTITY,
--	Nom NVARCHAR(30) NOT NULL,
--	DescriptionCourte NVARCHAR(500),
--	DescriptionLongue TEXT
--	);
--GO

--CREATE TABLE schema_article.Article
--	(
--	Identifiant INT PRIMARY KEY NOT NULL IDENTITY,
--	Titre NVARCHAR(100) NOT NULL,
--	DescriptionCourte NVARCHAR(500),
--	DescriptionLongue TEXT,
--	DatePublication DATETIME2 NOT NULL DEFAULT (GETDATE()),
--	DateModification DATETIME2 NOT NULL DEFAULT (GETDATE()),
--	IdentifiantUtilisateur TINYINT NOT NULL,
--	IdentifiantRubrique TINYINT NOT NULL
--	);
--GO

--CREATE TABLE schema_article.Media
--	(
--	Identifiant INT PRIMARY KEY NOT NULL IDENTITY,
--	Titre VARCHAR(100) NOT NULL,
--	DescriptionCourte NVARCHAR(500),
--	URL NVARCHAR(2000) NOT NULL,
--	Taille INT NOT NULL,
--	IdentifiantArticle INT NOT NULL,
--	IdentifiantTypeMedia TINYINT NOT NULL
--	);
--GO

--Question 11
--USE master;
--IF EXISTS(SELECT * FROM sys.sql_logins WHERE name = 'Redacteur')

--DROP LOGIN Redacteur;
--CREATE LOGIN Redacteur WITH PASSWORD = 'Redacteur';

--USE ArtNet;
--CREATE USER Redacteur FOR LOGIN Redacteur;


--USE master;
--IF EXISTS(SELECT * FROM sys.sql_logins WHERE name = 'Webmaster')

--DROP LOGIN Webmaster;
--CREATE LOGIN Webmaster WITH PASSWORD = 'Webmaster';

--USE ArtNet;
--CREATE USER Webmaster FOR LOGIN Webmaster;


--USE master;
--IF EXISTS(SELECT * FROM sys.sql_logins WHERE name = 'Visiteur')

--DROP LOGIN Visiteur;
--CREATE LOGIN Visiteur WITH PASSWORD = 'Visiteur';

--USE ArtNet;
--CREATE USER Visiteur FOR LOGIN Visiteur;

--Question 12
--GRANT SELECT, INSERT, UPDATE, DELETE ON Schema::schema_article TO Redacteur
--GRANT SELECT ON UtilisateurRubrique TO Redacteur
--GRANT SELECT ON TypeMedia TO Redacteur

--GRANT SELECT, INSERT, UPDATE, DELETE TO Webmaster

--GRANT INSERT ON Visite TO Visiteur

--Question 13
EXECUTE AS USER = 'Redacteur';

--Insert Article
INSERT INTO schema_article.Article(Titre, DatePublication, DateModification, IdentifiantUtilisateur, IdentifiantRubrique, DescriptionCourte, DescriptionLongue) VALUES
('Les Mains Sales', '02/01/2013', '06/01/2012', 2, 1,
'Les Mains sales est une pièce de théâtre en sept tableaux de Jean-Paul Sartre, écrite en 1948 et créée le 2 avril de la même année au théâtre Antoine à Paris, avec notamment André Luguet et François Périer.',
'Etenim si attendere diligenter, existimare vere de omni hac causa volueritis, sic constituetis, iudices, nec descensurum quemquam ad hanc accusationem fuisse, cui, utrum vellet, liceret, nec, cum descendisset, quicquam habiturum spei fuisse, nisi alicuius intolerabili libidine et nimis acerbo odio niteretur. Sed ego Atratino, humanissimo atque optimo adulescenti meo necessario, ignosco, qui habet excusationem vel pietatis vel necessitatis vel aetatis. Si voluit accusare, pietati tribuo, si iussus est, necessitati, si speravit aliquid, pueritiae. Ceteris non modo nihil ignoscendum, sed etiam acriter est resistendum.

Quid enim tam absurdum quam delectari multis inanimis rebus, ut honore, ut gloria, ut aedificio, ut vestitu cultuque corporis, animante virtute praedito, eo qui vel amare vel, ut ita dicam, redamare possit, non admodum delectari? Nihil est enim remuneratione benevolentiae, nihil vicissitudine studiorum officiorumque iucundius.

Ex his quidam aeternitati se commendari posse per statuas aestimantes eas ardenter adfectant quasi plus praemii de figmentis aereis sensu carentibus adepturi, quam ex conscientia honeste recteque factorum, easque auro curant inbracteari, quod Acilio Glabrioni delatum est primo, cum consiliis armisque regem superasset Antiochum. quam autem sit pulchrum exigua haec spernentem et minima ad ascensus verae gloriae tendere longos et arduos, ut memorat vates Ascraeus, Censorius Cato monstravit. qui interrogatus quam ob rem inter multos... statuam non haberet malo inquit ambigere bonos quam ob rem id non meruerim, quam quod est gravius cur inpetraverim mussitare.')

--Sélectionner les TypeMedia
SELECT * FROM TypeMedia

--Insérer une visite
INSERT INTO Visite(AdresseIP,Pays, Ville, Navigateur, Systeme, DateHeureDebut, DateHeureFin, IdentifiantArticle) VALUES
('127.0.0.65', 'FRANCE', 'Paris', 'IE', 'Win7', '12-10-13 12:33:00', '12-10-13 12:35:00', 1)

--Insérer une entrée dans UtilisateurRubrique
INSERT INTO UtilisateurRubrique(IdentifiantUtilisateur, IdentifiantRubrique) VALUES (2,1)

--Insérer un TypeMedia
INSERT INTO TypeMedia(Libelle) VALUES ('Vidéo')

--Supprimer les visites
DELETE FROM Visite WHERE Visite.Identifiant=1
REVERT;

EXECUTE AS USER = 'Webmaster';

--Insert Article
INSERT INTO schema_article.Article(Titre, DatePublication, DateModification, IdentifiantUtilisateur, IdentifiantRubrique, DescriptionCourte, DescriptionLongue) VALUES
('Les Mains Sales', '02/01/2013', '06/01/2012', 2, 1,
'Les Mains sales est une pièce de théâtre en sept tableaux de Jean-Paul Sartre, écrite en 1948 et créée le 2 avril de la même année au théâtre Antoine à Paris, avec notamment André Luguet et François Périer.',
'Etenim si attendere diligenter, existimare vere de omni hac causa volueritis, sic constituetis, iudices, nec descensurum quemquam ad hanc accusationem fuisse, cui, utrum vellet, liceret, nec, cum descendisset, quicquam habiturum spei fuisse, nisi alicuius intolerabili libidine et nimis acerbo odio niteretur. Sed ego Atratino, humanissimo atque optimo adulescenti meo necessario, ignosco, qui habet excusationem vel pietatis vel necessitatis vel aetatis. Si voluit accusare, pietati tribuo, si iussus est, necessitati, si speravit aliquid, pueritiae. Ceteris non modo nihil ignoscendum, sed etiam acriter est resistendum.

Quid enim tam absurdum quam delectari multis inanimis rebus, ut honore, ut gloria, ut aedificio, ut vestitu cultuque corporis, animante virtute praedito, eo qui vel amare vel, ut ita dicam, redamare possit, non admodum delectari? Nihil est enim remuneratione benevolentiae, nihil vicissitudine studiorum officiorumque iucundius.

Ex his quidam aeternitati se commendari posse per statuas aestimantes eas ardenter adfectant quasi plus praemii de figmentis aereis sensu carentibus adepturi, quam ex conscientia honeste recteque factorum, easque auro curant inbracteari, quod Acilio Glabrioni delatum est primo, cum consiliis armisque regem superasset Antiochum. quam autem sit pulchrum exigua haec spernentem et minima ad ascensus verae gloriae tendere longos et arduos, ut memorat vates Ascraeus, Censorius Cato monstravit. qui interrogatus quam ob rem inter multos... statuam non haberet malo inquit ambigere bonos quam ob rem id non meruerim, quam quod est gravius cur inpetraverim mussitare.')

--Sélectionner les TypeMedia
SELECT * FROM TypeMedia

--Insérer une visite
INSERT INTO Visite(AdresseIP,Pays, Ville, Navigateur, Systeme, DateHeureDebut, DateHeureFin, IdentifiantArticle) VALUES
('127.0.0.65', 'FRANCE', 'Paris', 'IE', 'Win7', '12-10-13 12:33:00', '12-10-13 12:35:00', 1)

--Insérer une entrée dans UtilisateurRubrique
INSERT INTO UtilisateurRubrique(IdentifiantUtilisateur, IdentifiantRubrique) VALUES (2,1)

--Insérer un TypeMedia
INSERT INTO TypeMedia(Libelle) VALUES ('Vidéo')

--Supprimer les visites
DELETE FROM Visite WHERE Visite.Identifiant=1
REVERT;

EXECUTE AS USER = 'Visiteur';

--Insert Article
INSERT INTO schema_article.Article(Titre, DatePublication, DateModification, IdentifiantUtilisateur, IdentifiantRubrique, DescriptionCourte, DescriptionLongue) VALUES
('Les Mains Sales', '02/01/2013', '06/01/2012', 2, 1,
'Les Mains sales est une pièce de théâtre en sept tableaux de Jean-Paul Sartre, écrite en 1948 et créée le 2 avril de la même année au théâtre Antoine à Paris, avec notamment André Luguet et François Périer.',
'Etenim si attendere diligenter, existimare vere de omni hac causa volueritis, sic constituetis, iudices, nec descensurum quemquam ad hanc accusationem fuisse, cui, utrum vellet, liceret, nec, cum descendisset, quicquam habiturum spei fuisse, nisi alicuius intolerabili libidine et nimis acerbo odio niteretur. Sed ego Atratino, humanissimo atque optimo adulescenti meo necessario, ignosco, qui habet excusationem vel pietatis vel necessitatis vel aetatis. Si voluit accusare, pietati tribuo, si iussus est, necessitati, si speravit aliquid, pueritiae. Ceteris non modo nihil ignoscendum, sed etiam acriter est resistendum.

Quid enim tam absurdum quam delectari multis inanimis rebus, ut honore, ut gloria, ut aedificio, ut vestitu cultuque corporis, animante virtute praedito, eo qui vel amare vel, ut ita dicam, redamare possit, non admodum delectari? Nihil est enim remuneratione benevolentiae, nihil vicissitudine studiorum officiorumque iucundius.

Ex his quidam aeternitati se commendari posse per statuas aestimantes eas ardenter adfectant quasi plus praemii de figmentis aereis sensu carentibus adepturi, quam ex conscientia honeste recteque factorum, easque auro curant inbracteari, quod Acilio Glabrioni delatum est primo, cum consiliis armisque regem superasset Antiochum. quam autem sit pulchrum exigua haec spernentem et minima ad ascensus verae gloriae tendere longos et arduos, ut memorat vates Ascraeus, Censorius Cato monstravit. qui interrogatus quam ob rem inter multos... statuam non haberet malo inquit ambigere bonos quam ob rem id non meruerim, quam quod est gravius cur inpetraverim mussitare.')

--Sélectionner les TypeMedia
SELECT * FROM TypeMedia

--Insérer une visite
INSERT INTO Visite(AdresseIP,Pays, Ville, Navigateur, Systeme, DateHeureDebut, DateHeureFin, IdentifiantArticle) VALUES
('127.0.0.65', 'FRANCE', 'Paris', 'IE', 'Win7', '12-10-13 12:33:00', '12-10-13 12:35:00', 1)

--Insérer une entrée dans UtilisateurRubrique
INSERT INTO UtilisateurRubrique(IdentifiantUtilisateur, IdentifiantRubrique) VALUES (2,1)

--Insérer un TypeMedia
INSERT INTO TypeMedia(Libelle) VALUES ('Vidéo')

--Supprimer les visites
DELETE FROM Visite WHERE Visite.Identifiant=1
REVERT;


