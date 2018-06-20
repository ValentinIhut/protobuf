package com.protobuf.example.demo.utils;

import com.protobuf.example.demo.dto.EventDto;
import com.protobuf.example.demo.proto.EventsProto.Event;

/**
 * @author valentin.ihut
 * @since 1.0.0
 */
public class DtoToProtoConverter {

  public static Event convertDtoToProto(EventDto eventDto) {
    return Event.newBuilder().setTimestamp(eventDto.getTimestamp()).setUserId(eventDto.getUserId()).setEvent(eventDto.getEvent())
        .build();
  }

}
