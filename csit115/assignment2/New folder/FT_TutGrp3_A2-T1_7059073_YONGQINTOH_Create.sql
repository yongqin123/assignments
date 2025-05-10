CREATE TABLE Person (
passportNumber     VARCHAR(20)  NOT NULL,
firstName          VARCHAR(30)  NOT NULL,
lastName           VARCHAR(30)  NOT NULL,
dateOfBirth        DATE       NOT NULL,
gender             CHAR(1)    NOT NULL,
address            VARCHAR(50)  NOT NULL,
telNo              VARCHAR(20)  NULL,
email              VARCHAR(50)  NOT NULL,

CONSTRAINT Person_pkey PRIMARY KEY(passportNumber),
CONSTRAINT Person_ckey1 UNIQUE (firstName),
CONSTRAINT Person_ckey2 UNIQUE (lastName),
CONSTRAINT Person_ckey3 UNIQUE (dateOfBirth),
CONSTRAINT Person_check4 CHECK (gender in ('M', 'F', 'O'))
);

CREATE TABLE Chef (
passportNumber   VARCHAR(20)    NOT NULL,
culinaryCerts    VARCHAR(300)   NOT NULL,
competitionExpr  VARCHAR(300)   NULL,

CONSTRAINT Chef_pkey PRIMARY KEY(passportNumber),
CONSTRAINT Chef_fkey FOREIGN KEY(passportNumber) REFERENCES Person(passportNumber)
);

CREATE TABLE Client (
passportNumber     VARCHAR(20)  NOT NULL,
preferredCuisine   VARCHAR(100) NULL,
preferredPaymType  VARCHAR(20)  NOT NULL,
creditCardNumber   VARCHAR(20)  NULL,
creditCardType     VARCHAR(20)  NULL,
issuingBank        VARCHAR(50)  NULL,

CONSTRAINT Client_pkey PRIMARY KEY(passportNumber),
CONSTRAINT Client_fkey FOREIGN KEY(passportNumber) REFERENCES Person(passportNumber)
);

CREATE TABLE Specialty (
specialtyNumber CHAR(3)      NOT NULL,
description     VARCHAR(100)   NOT NULL,
ingredients     VARCHAR(300)   NOT NULL,
recipe          VARCHAR(1000)  NULL,

CONSTRAINT Specialty_pkey PRIMARY KEY(specialtyNumber),
CONSTRAINT Specialty_check1 CHECK (specialtyNumber BETWEEN 0 AND 999),
CONSTRAINT Specialty_check2 CHECK (CHAR_LENGTH(specialtyNumber) = 3)
);

CREATE TABLE PartyEvent (
passportNumber_Chef    VARCHAR(20)  NOT NULL,
eventID                CHAR(10)   NOT NULL,
partySize              CHAR(3)    NOT NULL,
cusinePkg              VARCHAR(100) NOT NULL,
eventDate              DATE       NOT NULL,
eventTime              TIME       NOT NULL,  
eventVenue             VARCHAR(50)  NOT NULL,
passportNumber_Client  VARCHAR(20)  NOT NULL,

CONSTRAINT PE_pkey PRIMARY KEY(eventID),
CONSTRAINT PE_ckey1 UNIQUE (eventDate),
CONSTRAINT PE_ckey2 UNIQUE (eventTime),
CONSTRAINT PE_ckey3 UNIQUE (eventVenue),
CONSTRAINT PE_fkey1 FOREIGN KEY(passportNumber_Chef) REFERENCES Chef(passportNumber),
CONSTRAINT PE_fkey2 FOREIGN KEY(passportNumber_Client) REFERENCES Client(passportNumber),
CONSTRAINT PE_check1 CHECK (partySize BETWEEN 0 AND 999),
CONSTRAINT PE_check2 CHECK (CHAR_LENGTH(partySize) = 3)
);
