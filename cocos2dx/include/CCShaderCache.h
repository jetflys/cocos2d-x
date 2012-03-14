/*
 * cocos2d for iPhone: http://www.cocos2d-iphone.org
 *
 * Copyright (c) 2008-2010 Ricardo Quesada
 * Copyright (c) 2011 Zynga Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __CCSHADERCACHE_H__
#define __CCSHADERCACHE_H__

#include "CCMutableDictionary.h"

NS_CC_BEGIN

class CCGLProgram;

/** CCShaderCache
 Singleton that stores manages GL shaders
 @since v2.0
 */
class CC_DLL CCShaderCache : public CCObject 
{
public:
	CCShaderCache();

	virtual ~CCShaderCache();
	/** returns the shared instance */
	static CCShaderCache* sharedShaderCache();

	/** purges the cache. It releases the retained instance. */
	static void purgeSharedShaderCache();

	/** loads the default shaders */
	void loadDefaultShaders();

	/** returns a GL program for a given key */
	CCGLProgram * programForKey(const char* key);

	/** adds a CCGLProgram to the cache for a given name */
	void addProgram(CCGLProgram* program, const char* key);

private:
	bool init();

	CCMutableDictionary<std::string, CCGLProgram*>* programs_;

};

NS_CC_END

#endif /* __CCSHADERCACHE_H__ */