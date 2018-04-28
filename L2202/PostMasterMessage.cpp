class PostMasterMessage : public MailMessage
{
public:
    PostMasterMessage();
    PostMasterMessage(
        pAddress sender,
        pAddress recipient,
        pString subject,
        pDate creationDate);

    //other constructors here
    //remember to include copy constructors
    //as well as constructor from storage
    //and constructor from wire format
    //also include constructors form other format
    ~PostMasterMessage();
    pAddress& getSender() const;
    void setSender(pAddress&);
    //other member accessors
    //operator functions here, include operator equals
    //and conversion routines to turn PostMaster messages
    //into messages of other formats.
    
private:
    pAddress sender;
    pAddress recipient;
    pString subject;
    pDate creationDate;
    pDate lastModDate;
    pDate receiptDate;
    pDate firstReadDate;
    pDate lastReadDate;
};