/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * fastcdr_LICENSE file included in this fastcdr distribution.
 *
 *************************************************************************
 * 
 * @file FlowControlExamplePublisher.h
 * This header file contains the declaration of the publisher functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _FLOWCONTROLEXAMPLE_PUBLISHER_H_
#define _FLOWCONTROLEXAMPLE_PUBLISHER_H_

#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/publisher/PublisherListener.h>

#include "FlowControlExamplePubSubTypes.h"

using namespace eprosima::fastrtps;

class FlowControlExamplePublisher 
{
public:
	FlowControlExamplePublisher();
	virtual ~FlowControlExamplePublisher();
	bool init();
	void run();
private:
	Participant *mp_participant;
	Publisher *mp_fast_publisher;
	Publisher *mp_slow_publisher;
	
	class PubListener : public PublisherListener
	{
	public:
		PubListener() : n_matched(0){};
		~PubListener(){};
		void onPublicationMatched(Publisher* pub,MatchingInfo& info);
		int n_matched;
	} m_listener;
	FlowControlExamplePubSubType myType;
};

#endif // _FLOWCONTROLEXAMPLE_PUBLISHER_H_
