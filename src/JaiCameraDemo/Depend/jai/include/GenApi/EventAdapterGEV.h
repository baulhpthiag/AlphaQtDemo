//-----------------------------------------------------------------------------
//  (c) 2006 by Basler Vision Technologies
//  Section:  Vision Components
//  Project:  GenApi
//    Author:  Fritz Dierks
//  $Header$
//
//  License: This file is published under the license of the EMVA GenICam  Standard Group.
//  A text file describing the legal terms is included in  your installation as 'GenICam_license.pdf'.
//  If for some reason you are missing  this file please contact the EMVA or visit the website
//  (http://www.genicam.org) for a full copy.
//
//  THIS SOFTWARE IS PROVIDED BY THE EMVA GENICAM STANDARD GROUP "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE EMVA GENICAM STANDARD  GROUP
//  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  DATA, OR PROFITS;
//  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  THEORY OF LIABILITY,
//  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE  OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------
/**
\file
\brief    Declaration of the CEventAdapterGEV class.
*/

#ifndef GENAPI_EVENTADAPTERGEV_H
#define GENAPI_EVENTADAPTERGEV_H

#include "EventAdapter.h"

namespace GenApi
{

    /* ------------------------------------------- */
    // Declaration of GigE Vision Event message structures

    // some useful macros
    #if defined( _MSC_VER )
        #define PACK_STRUCT
    #elif defined (__GNUC__)
        // While gcc-4 understands #pragma pack,
        // gcc-3 does not
        #define PACK_STRUCT __attribute__((packed))
    #else
    #   error Unknown platform
    #endif

    // make sure everything is properly packed
#pragma pack(push, 1)

    //! header of a GVCP request packet
    typedef struct PACK_STRUCT GVCP_REQUEST_HEADER
    {
        uint8_t  Magic;
        uint8_t  Flags;
        uint16_t Command;
        uint16_t Length;
        uint16_t ReqId;
    } GVCP_REQUEST_HEADER;

    //! header describing a GVCP event item
    typedef struct PACK_STRUCT GVCP_EVENT_ITEM
    {
        uint16_t Reserved;
        uint16_t EventId;
        uint16_t StreamChannelId;
        uint16_t BlockId;
        uint32_t TimestampHigh;
        uint32_t TimestampLow;
    } GVCP_EVENT_ITEM;

    //! Layout of a GVCP event request packet
    typedef struct PACK_STRUCT GVCP_EVENT_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
        GVCP_EVENT_ITEM Items[ 1 ];
    } GVCP_EVENT_REQUEST;

    //! Layout of a GVCP event data request packet
    typedef struct PACK_STRUCT GVCP_EVENTDATA_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
        GVCP_EVENT_ITEM Event;
        uint32_t Data[ 1 ];
    } GVCP_EVENTDATA_REQUEST;

    const uint8_t COMMAND_MAGIC = 0x42;

    typedef enum GVCP_MESSAGE_TAGS
    {
        TAG_EVENT_CMD         = 0xc0,
        TAG_EVENTDATA_CMD     = 0xc2
    } GVCP_MESSAGE_TAGS;

    // restore the previous packing
#pragma pack(pop)
    /* ------------------------------------------- */


    //! Connects a GigE Event to a node map
    class GENAPI_DECL CEventAdapterGEV : public  CEventAdapter
    {
    public:
        //! Constructor
        CEventAdapterGEV(INodeMap* pNodeMap = NULL);

        //! Destructor
        virtual ~CEventAdapterGEV();

        virtual void DeliverMessage( const uint8_t msg[], uint32_t numBytes );

        //! Delivers the Events listed in the Event packet
        void DeliverEventMessage(const GVCP_EVENT_REQUEST *pEvent);

        //! Delivers the Event + Data listed in the EventData packet
        void DeliverEventMessage(const GVCP_EVENTDATA_REQUEST *pEventData);

    private:
        void DeliverEventItem( const GVCP_EVENT_ITEM *pItem, unsigned int length);

    };
}

#endif // GENAPI_EVENTADAPTERGEV_H
