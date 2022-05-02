-- phpMyAdmin SQL Dump
-- version 5.1.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 28, 2022 at 04:07 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.5
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";
--
-- Database: `my_shop`
--
-- --------------------------------------------------------
--
-- Table structure for table `artikel`
--
CREATE TABLE `artikel` (
  `ArtNr` int(10) NOT NULL,
  `Artikel` varchar(40) NOT NULL,
  `Preis` float NOT NULL,
  `Waehrg` varchar(40) NOT NULL
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4;
--
-- Dumping data for table `artikel`
--
INSERT INTO `artikel` (`ArtNr`, `Artikel`, `Preis`, `Waehrg`)
VALUES (69, 'Bleistift', 1, 'Euro');
-- --------------------------------------------------------
--
-- Table structure for table `kunde`
--
CREATE TABLE `kunde` (
  `KNr` int(10) NOT NULL,
  `VName` varchar(40) NOT NULL,
  `NName` varchar(40) NOT NULL,
  `Strasse` varchar(40) NOT NULL,
  `Nr` int(10) NOT NULL,
  `Plz` int(10) NOT NULL,
  `Ort` varchar(40) NOT NULL
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4;
--
-- Dumping data for table `kunde`
--
INSERT INTO `kunde` (
    `KNr`,
    `VName`,
    `NName`,
    `Strasse`,
    `Nr`,
    `Plz`,
    `Ort`
  )
VALUES (
    7,
    'Philipp',
    'Rolinek',
    'Hauserstrasse',
    1,
    1234,
    'Ortheim'
  );
-- --------------------------------------------------------
--
-- Table structure for table `rechnung`
--
CREATE TABLE `rechnung` (
  `RNr` int(10) NOT NULL,
  `Datum` date DEFAULT NULL,
  `KNr` int(10) NOT NULL
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4;
--
-- Dumping data for table `rechnung`
--
INSERT INTO `rechnung` (`RNr`, `Datum`, `KNr`)
VALUES (1, '2022-04-21', 7);
-- --------------------------------------------------------
--
-- Table structure for table `rechnungspositionen`
--
CREATE TABLE `rechnungspositionen` (
  `RNr` int(10) NOT NULL,
  `RPNr` int(10) NOT NULL,
  `ArtNr` int(10) NOT NULL,
  `Anz` int(10) NOT NULL
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4;
--
-- Dumping data for table `rechnungspositionen`
--
INSERT INTO `rechnungspositionen` (`RNr`, `RPNr`, `ArtNr`, `Anz`)
VALUES (1, 1, 69, 5);
--
-- Indexes for dumped tables
--
--
-- Indexes for table `artikel`
--
ALTER TABLE `artikel`
ADD PRIMARY KEY (`ArtNr`);
--
-- Indexes for table `kunde`
--
ALTER TABLE `kunde`
ADD PRIMARY KEY (`KNr`);
--
-- Indexes for table `rechnung`
--
ALTER TABLE `rechnung`
ADD PRIMARY KEY (`RNr`),
  ADD KEY `fk_rechnung_kunde` (`KNr`);
--
-- Indexes for table `rechnungspositionen`
--
ALTER TABLE `rechnungspositionen`
ADD PRIMARY KEY (`RNr`, `RPNr`),
  ADD KEY `fk_position_artikel` (`ArtNr`);
--
-- Constraints for dumped tables
--
--
-- Constraints for table `rechnung`
--
ALTER TABLE `rechnung`
ADD CONSTRAINT `fk_rechnung_kunde` FOREIGN KEY (`KNr`) REFERENCES `kunde` (`KNr`) ON UPDATE CASCADE;
--
-- Constraints for table `rechnungspositionen`
--
ALTER TABLE `rechnungspositionen`
ADD CONSTRAINT `fk_position_artikel` FOREIGN KEY (`ArtNr`) REFERENCES `artikel` (`ArtNr`) ON UPDATE CASCADE,
  ADD CONSTRAINT `fk_rechnung_position` FOREIGN KEY (`RNr`) REFERENCES `rechnung` (`RNr`) ON DELETE NO ACTION ON UPDATE CASCADE;
COMMIT;