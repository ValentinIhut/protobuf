package com.protobuf.example.demo.dto;

import com.fasterxml.jackson.annotation.JsonIgnore;
import java.time.Instant;
import javax.validation.constraints.NotNull;

/**
 * @author valentin.ihut
 * @since 1.0.0
 */
public class EventDto {

  @JsonIgnore
  private String timestamp = Instant.now().toString();

  @NotNull
  private String userId;
  @NotNull
  private String event;

  public String getTimestamp() {
    return timestamp;
  }

  public String getUserId() {
    return userId;
  }

  public void setUserId(String userId) {
    this.userId = userId;
  }

  public String getEvent() {
    return event;
  }

  public void setEvent(String event) {
    this.event = event;
  }
}
