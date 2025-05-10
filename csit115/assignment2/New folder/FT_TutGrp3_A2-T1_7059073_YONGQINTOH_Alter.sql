/* Assn2, Task1, Qn(i) */ 
ALTER TABLE Client DROP FOREIGN KEY Client_fkey;
ALTER TABLE Client
  ADD CONSTRAINT Client_fkey FOREIGN KEY (passportNumber) 
  REFERENCES Person(passportNumber) ON UPDATE CASCADE ON DELETE CASCADE;

/* Assn2, Task1, Qn(ii) */ 
ALTER TABLE Chef MODIFY competitionExpr VARCHAR(1000) NULL;

/* Assn2, Task1, Qn(iii) */ 
ALTER TABLE PartyEvent ADD COLUMN duration CHAR(2) NOT NULL; 
ALTER TABLE PartyEvent ADD CONSTRAINT PE_check CHECK (duration BETWEEN 0 AND 99);

/* Assn2, Task1, Qn(iv) */ 
ALTER TABLE Client ADD COLUMN countryOfOrigin VARCHAR(40) NOT NULL;

