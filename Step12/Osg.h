#pragma once
#include <osgViewer/Viewer>
#include <osg/Node>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <iostream>
#include <osgManipulator/TranslateAxisDragger>
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osg/NodeVisitor>
#include <osg/Point>

#include <osgGA/TrackballManipulator>
#include <osgManipulator/TrackballDragger>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgViewer/api/win32/GraphicsWindowWin32>

#include <iostream>
#include "DraggerContainer.h"
#include "PickHandler.h"

class COsg
{
public:
	COsg(HWND hWnd);
	~COsg(void);
	void initOsg(std::string fileName);
	osgViewer::Viewer * getViewer(void);
	static void Render(void* ptr);
	osg::ref_ptr<osg::Node> readPly2(std::string fileName);
	osg::ref_ptr<osg::Node> readPwn(std::string pwnFileName);
	osg::ref_ptr<osg::Vec3Array> calcNormalList(osg::ref_ptr<osg::Vec3Array> vertexList, osg::ref_ptr<osg::DrawElementsUInt> faceList);
	static osg::Vec3 calcFaceNormal(osg::Vec3 vertex0, osg::Vec3 vertex1, osg::Vec3 vertex2);
private:
	void initCameraConfig(void);
	void initManipulators(void);

private:
	HWND m_hWnd;
	std::string mFileName;
	osgViewer::Viewer * mViewer;
	osg::ref_ptr<osg::Group> mRoot;
	//osg::ref_ptr<osg::Node> mModel;
	osg::ref_ptr<osgGA::TrackballManipulator> trackball;
	osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator;
};
