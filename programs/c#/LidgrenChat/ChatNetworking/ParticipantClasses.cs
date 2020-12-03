using Lidgren.Network;
using System;
using System.Collections.Generic;

namespace ChatNetworking
{
    public class Participant
    {
        public string Name      { get; set; }
        public string EndPoint  { get; set; }

        public Participant()
        {

        }

        public Participant(string _name, string _endPoint)
        {
            Name     = _name;
            EndPoint = _endPoint;
        }
    }

    public class ParticipantMessage
    {
        public string SenderName    { get; set; }
        public string Message       { get; set; }

        public ParticipantMessage()
        {

        }

        public ParticipantMessage(string _senderName, string _message)
        {
            SenderName  = _senderName;
            Message     = _message;
        }
    }

    public class ParticipantMessageEventArgs : EventArgs
    {
        public ParticipantMessageEventArgs(ParticipantMessage _newMessage)
        {
            SenderName  = _newMessage.SenderName;
            Message     = _newMessage.Message;
            Time        = DateTime.UtcNow;
        }

        public string   SenderName  { get; private set; }
        public string   Message     { get; private set; }
        public DateTime Time        { get; private set; }
    }

    public class ConnectedParticipantListEventArgs : EventArgs
    {
        public ConnectedParticipantListEventArgs(List<Participant> _participantList)
        {
            ConnectedList = _participantList;
        }

        public List<Participant> ConnectedList { get; private set; }
    }
}
