//
//  HarmoniumAudioEngine.h
//  LidAngleSensor
//
//  Created by Vedaant Rajeshirke on 9/27/25.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface HarmoniumAudioEngine : NSObject

@property (nonatomic, assign, readonly) BOOL isEngineRunning;

- (instancetype)init;
- (void)startEngine;
- (void)stopEngine;

// Note control methods
- (void)playNote:(int)midiNote;
- (void)releaseNote:(int)midiNote;
- (void)processFadesWithDeltaTime:(double)deltaTime;


/**
 * Returns the number of notes currently being held down.
 */
- (NSUInteger)activeNoteCount;

/**
 * Updates the volume of all playing notes.
 * @param volume The target volume, from 0.0 to 1.0.
 */
- (void)updateVolume:(float)volume;

@end
