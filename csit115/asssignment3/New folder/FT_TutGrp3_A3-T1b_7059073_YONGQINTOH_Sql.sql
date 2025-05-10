/* Rows added into BOOK */
SELECT * FROM BOOK WHERE BookID NOT IN (SELECT BookID FROM yqt817_DOC);

/* Rows deleted from BOOK */
SELECT * FROM yqt817_DOC  WHERE BookID NOT IN (SELECT BookID FROM BOOK);

/* Rows changed */
SELECT BookID, Title, Price FROM (SELECT BOOK.BookID, BOOK.Title, BOOK.Price, (yqt817_DOC.Price) AS Price1 FROM BOOK JOIN yqt817_DOC ON BOOK.BookID = yqt817_DOC.BookID)TAB WHERE Price != Price1;






