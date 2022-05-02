# TODO: mRNA = tRNA output

#! Nicht Mutiert:
# CCTATTGGTCTATTTTCCACCCTTAGGCTGCT
#! Codiert:
# GCT GCT
#! Codogen:
# CGA CGA
#! mRNA:
# CGA CGA
#! tRNA:
# GCU GCU
#! Sonne:
# ARG ARG
#! Aminosaeuren:
# Arginin Arginin

#! Mutiert:
# CCTATTAGTCTATTTTCCACCCTTAGGCTGCT
#! Codiert:
# TCT ATT TTC CAC CCT TAG GCT GCT
#! Codogen:
# AGA TAA AAG GTG GGA ATC CGA CGA
#! mRNA:
# UCU AUU UUC CAC CCU UAG GCU GCU
#! tRNA:
# AGA UAA AAG GUG GGA AUC CGA CGA
#! Sonne:
# SER ILE PHE HIS PRO STP ALA ALA
#! Aminosaeuren:
# Serin Isoleucin Phenylalanin Histidin Prolin STOP Alanin Alanin

# Codiert
# Codogen: Codiert (A=T G=C)
# mRNA: Codogen (T=U)
# tRNA: mRNA (A=U C=G)
# AS: Codesonne(mRNA)

globCodiert = str()
globCodogen = str()
globMrna = str()
globTrna = str()
globCodesonneStr = str()
globSaeureStr = str()
valid_input = 0


def codesonne(sequenz):
    match sequenz:
        case "UUU":
            return "PHE"
        case "UUC":
            return "PHE"
        case "UUA":
            return "LEU"
        case "UUG":
            return "LEU"
        case "UCU":
            return "SER"
        case "UCC":
            return "SER"
        case "UCA":
            return "SER"
        case "UCG":
            return "SER"
        case "UAU":
            return "TYR"
        case "UAC":
            return "TYR"
        case "UAA":
            return "STP"
        case "UAG":
            return "STP"
        case "UGU":
            return "CYS"
        case "UGC":
            return "CYS"
        case "UGA":
            return "STP"
        case "UGG":
            return "TRP"
        case "CUU":
            return "LEU"
        case "CUC":
            return "LEU"
        case "CUA":
            return "LEU"
        case "CUG":
            return "LEU"
        case "CCU":
            return "PRO"
        case "CCC":
            return "PRO"
        case "CCA":
            return "PRO"
        case "CCG":
            return "PRO"
        case "CAU":
            return "HIS"
        case "CAC":
            return "HIS"
        case "CAA":
            return "GLN"
        case "CAG":
            return "GLN"
        case "CGU":
            return "ARG"
        case "CGC":
            return "ARG"
        case "CGA":
            return "ARG"
        case "CGG":
            return "ARG"
        case "AUU":
            return "ILE"
        case "AUC":
            return "ILE"
        case "AUA":
            return "ILE"
        case "AUG":
            return "MET"
        case "ACU":
            return "THR"
        case "ACC":
            return "THR"
        case "ACA":
            return "THR"
        case "ACG":
            return "THR"
        case "AAU":
            return "ASN"
        case "AAC":
            return "ASN"
        case "AAA":
            return "LYS"
        case "AAG":
            return "LYS"
        case "AGU":
            return "SER"
        case "AGC":
            return "SER"
        case "AGA":
            return "ARG"
        case "AGG":
            return "ARG"
        case "GUU":
            return "VAL"
        case "GUC":
            return "VAL"
        case "GUA":
            return "VAL"
        case "GUG":
            return "VAL"
        case "GCU":
            return "ALA"
        case "GCC":
            return "ALA"
        case "GCA":
            return "ALA"
        case "GCG":
            return "ALA"
        case "GAU":
            return "ASP"
        case "GAC":
            return "ASP"
        case "GAA":
            return "GLU"
        case "GAG":
            return "GLU"
        case "GGU":
            return "GLY"
        case "GGC":
            return "GLY"
        case "GGA":
            return "GLY"
        case "GGG":
            return "GLY"
        case _:
            return "ERR"


def sequenzierung(codesonnecode):
    match codesonnecode:
        case "ALA":
            return "Alanin"
        case "ARG":
            return "Arginin"
        case "ASN":
            return "Asparagin"
        case "ASP":
            return "Asparaginsaeure"
        case "CYS":
            return "Cystein"
        case "GLN":
            return "Glutamin"
        case "GLU":
            return "Glutaminsaeure"
        case "GLY":
            return "Glycin"
        case "HIS":
            return "Histidin"
        case "ILE":
            return "Isoleucin"
        case "LEU":
            return "Leucin"
        case "LYS":
            return "Lysin"
        case "MET":
            return "Methionin"
        case "PHE":
            return "Phenylalanin"
        case "PRO":
            return "Prolin"
        case "SER":
            return "Serin"
        case "THR":
            return "Threonin"
        case "TRP":
            return "Tryptophan"
        case "TYR":
            return "Tyrosin"
        case "VAL":
            return "Valin"
        case "STP":
            return "STOP"
        case _:
            return "ERR"


def getCodesonne(mrnaString):
    cdsString = str()
    returnString = str()
    i = 0
    for c in mrnaString:
        cdsString += c
        i += 1
        if i == 3:
            returnString += codesonne(cdsString)
            cdsString = ""
            i = 0
    return returnString


def printSequezierung(codeString):
    seqString = str()
    returnString = str()
    i = 0
    for c in codeString:
        if c == " ":
            pass
        else:
            seqString += c
            i += 1
            if i == 3:
                returnString += sequenzierung(seqString)
                returnString += " "
                seqString = ""
                i = 0
    return returnString


def printThree(text):
    returntext = str()
    i = 0
    for c in text:
        returntext += c
        i += 1
        if i == 3:
            returntext += " "
            i = 0
    return returntext


def codoiertToCodogen(codiert):
    # codiert -> codogen
    codogen = str()
    for c in codiert:
        if c == "A":
            codogen += "T"
        if c == "T":
            codogen += "A"
        if c == "G":
            codogen += "C"
        if c == "C":
            codogen += "G"
        if c == " ":
            pass
    return codogen


def codogenToMrna(codogen):
    # codogen -> mRNA
    mrna = str()
    for c in codogen:
        if c == "A":
            mrna += "U"
        if c == "T":
            mrna += "A"
        if c == "G":
            mrna += "C"
        if c == "C":
            mrna += "G"
        if c == " ":
            pass
    return mrna


def mRnaToCodogen(mrna):
    # mrna -> codogen
    codogen = str()
    for c in mrna:
        if c == "A":
            codogen += "T"
        if c == "U":
            codogen += "A"
        if c == "G":
            codogen += "C"
        if c == "C":
            codogen += "G"
        if c == " ":
            pass
    return codogen


def mrnaToTrna(mrna):
    # mRNA -> tRNA
    trna = str()
    for c in mrna:
        if c == "A":
            trna += "U"
        if c == "U":
            trna += "A"
        if c == "G":
            trna += "C"
        if c == "C":
            trna += "G"
    return trna


def eliminateSpaces(input):
    returnStr = str()
    for c in input:
        if c != " ":
            returnStr += c
    return returnStr


def findTTAG(codiert=str()):
    ttagStr = str()
    index = codiert.find("TTAG")
    if index != -1:
        ttagStr = codiert[index+4:]
    return ttagStr


# main
print("Start Value")
print("Codiert = 1")
print("Codogen = 2")
print("mRNA    = 3")
print("tRNA    = 4")
print("TTAGcod = 5")
selection = input("Selct: ")
print(" ")
match selection:
    case "1":
        valid_input = 1
        globCodiert = eliminateSpaces(input("Codiert: "))
        globCodogen = codoiertToCodogen(globCodiert)
        globMrna = codogenToMrna(globCodogen)
        globTrna = mrnaToTrna(globMrna)
        globCodesonneStr = getCodesonne(globMrna)
    case "2":
        valid_input = 1
        globCodogen = eliminateSpaces(input("Codogen: "))
        globCodiert = codoiertToCodogen(globCodogen)
        globMrna = codogenToMrna(globCodogen)
        globTrna = mrnaToTrna(globMrna)
        globCodesonneStr = getCodesonne(globMrna)
    case "3":
        valid_input = 1
        globMrna = eliminateSpaces(input("mRNA: "))
        globCodogen = mRnaToCodogen(globMrna)
        globCodiert = codoiertToCodogen(globCodogen)
        globTrna = mrnaToTrna(globMrna)
        globCodesonneStr = getCodesonne(globMrna)
    case "4":
        valid_input = 1
        globTrna = eliminateSpaces(input("tRNA: "))
        globMrna = mrnaToTrna(globTrna)
        globCodogen = mRnaToCodogen(globMrna)
        globCodiert = codoiertToCodogen(globCodogen)
        globCodesonneStr = getCodesonne(globMrna)
    case "5":
        valid_input = 1
        globCodiert = eliminateSpaces(input("Codiert: "))
        globCodiert = findTTAG(globCodiert)
        globCodogen = codoiertToCodogen(globCodiert)
        globMrna = codogenToMrna(globCodogen)
        globTrna = mrnaToTrna(globMrna)
        globCodesonneStr = getCodesonne(globMrna)
    case _:
        print("Invalid Input!")


if valid_input == 1:
    print(" ")
    print("Codiert: " + printThree(globCodiert))
    print("Codogen: " + printThree(globCodogen))
    print("mRNA   : " + printThree(globMrna))
    print("tRNA   : " + printThree(globTrna))
    print("Sonne  : " + printThree(globCodesonneStr))
    print("Saeuren: " + printSequezierung(globCodesonneStr))
